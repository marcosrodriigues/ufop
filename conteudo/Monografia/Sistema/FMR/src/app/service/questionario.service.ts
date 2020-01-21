import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class QuestionarioService {

  constructor(private _http : HttpClient, private _url : UrlService) { }

  private baseUrl: string = this._url.baseUrl() + "/pergunta";

  getAll() {
    return this._http.get(this.baseUrl);
  }
}
