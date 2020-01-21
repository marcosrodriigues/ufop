import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class UniversidadeService {

  private baseUrl: string = this._url.baseUrl() + "/universidade";

  constructor(private _http : HttpClient, private _url : UrlService) { }

  getAll() {
    return this._http.get(this.baseUrl);
  }

  save(universidade) {
    return this._http.post(this.baseUrl, universidade);
  }


}
