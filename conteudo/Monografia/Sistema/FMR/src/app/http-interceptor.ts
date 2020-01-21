import { Injectable } from '@angular/core';
import { HttpRequest, HttpHandler, HttpEvent, HttpInterceptor, HttpResponse } from '@angular/common/http';
import { Observable } from 'rxjs';
import { UserService } from './service/user.service';
import { tap } from "rxjs/operators";
import { UrlService } from './service/default/url.service';

@Injectable()
export class MyHttpInterceptor implements HttpInterceptor {
    constructor(private _user: UserService, private _url : UrlService) {}

    intercept(request: HttpRequest<any>, next: HttpHandler) : Observable<HttpEvent<any>> {
        if (request.url.indexOf(this._url.baseUrl()) < 0) return next.handle(request);

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