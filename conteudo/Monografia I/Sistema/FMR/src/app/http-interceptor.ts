import { Injectable } from '@angular/core';
import { HttpRequest, HttpHandler, HttpEvent, HttpInterceptor, HttpResponse } from '@angular/common/http';
import { Observable } from 'rxjs';
import { UserService } from './service/user.service';
import { tap } from "rxjs/operators";

@Injectable()
export class MyHttpInterceptor implements HttpInterceptor {
    constructor(private _user: UserService) {}

    intercept(request: HttpRequest<any>, next: HttpHandler) : Observable<HttpEvent<any>> {
        if (request.url.indexOf('localhost') < 0) return next.handle(request);

        //console.log("Token: " + this._user.getToken());
        if (this._user.getToken() != '') {
            const updateRequest = request.clone({
                headers: request.headers.set('Authorization', `Bearer ${this._user.getToken()}`)
            });
            //console.log(updateRequest);
            return next.handle(updateRequest)
            .pipe(
                tap(
                    event => {
                        if (event instanceof HttpResponse) {
                            //console.log("okey");
                        }
                    },
                    error => {
                        if (error instanceof HttpResponse) {
                            //console.log("error");
                        }
                    }
                )
            )
        }

        return next.handle(request);
    }

}